// DECLARATIONS V -----------------------------------------------------------
// CONSTANTS
// LiveFlow credentials
const String LF_USERNAME = "esp32mc";
const String LF_PASSWORD = "Wachtwoord1.";
// API info
const String BASE_URL = "https://leverage.liveflow.nl/api";

// OBJECTS
HTTPClient http;

// FUNCTIONS V --------------------------------------------------------------

// REQUEST FUNCTIONS
// Get request
// ...

// Put request
// ...

// Post request
JSONVar postRequest(String path, String body[], byte bodyLength) {
  // Declarations
  JSONVar response;
  String bodyString = generateBodyString(body, bodyLength);

  // Http post setup
  http.begin(BASE_URL + path);
  http.addHeader("Content-Type", "application/json");
  // Only add token when the post request is not to get a token
  if(path != "/auth") {
    http.addHeader("X-auth-token", JWTToken);
  }

  // Request & response
  bool error = handleErrors(http.POST(bodyString));
  if(!error) {
    response = JSON.parse(http.getString());
  }
  http.end();

  return response;
}

// Error handling
bool handleErrors(int httpResponseCode) {
  switch(httpResponseCode) {
    case 400:
      Serial.println("400 status");
      return true;
    case 401:
      Serial.println("401 status");
      return true;
    case 403:
      Serial.println("403 status");
      return true;
    case 500:
      Serial.println("500 status");
      return true;
  }

  return false;
}

// ACTIONS
// Set JWT token
void setJWTToken() {
  String body[] = {
    "username", LF_USERNAME,
    "password", LF_PASSWORD
  };
  
  JWTToken = JSON.stringify(postRequest("/auth", body, ARRAYLENGTH(body))["token"]);

  if(JWTToken != "null") {
    Serial.print("JWTToken: ");
    Serial.println(JWTToken);
  }
  else {
    JWTToken = "";
  }
}

// HELP FUNCTIONS
// Generate a string that represents the body of a (post) request
String generateBodyString(String keysAndValues[], byte arrayLength) {
  // If array has an even amount of values (which means that there are as many keys as values)
  if(arrayLength % 2 == 0) {
    // Create JSON object
    JSONVar bodyObject;
    // Loop through array
    for(byte i = 0; i < arrayLength; i += 2) {
      // Add key and corresponding value to JSON object
      bodyObject[keysAndValues[i]] = keysAndValues[i + 1];
    }
    // Return stringified JSON object
    return JSON.stringify(bodyObject);
  }
  // If the array has more keys than values (not an even amount of keys and values)
  else {
    Serial.println("Error: There are more keys then values");
    return "";
  }
}
