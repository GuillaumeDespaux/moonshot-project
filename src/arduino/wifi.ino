

void wifi_setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(Internet.ssid);

  WiFi.begin(Internet.ssid, Internet.password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void wifi() {
  NetworkClient client = server.accept();  // listen for incoming clients

  if (client) {                     // if you get a client,
    Serial.println("New Client.");  // print a message out the serial port
    String currentLine = "";        // make a String to hold incoming data from the client
    while (client.connected()) {    // loop while the client's connected
      if (client.available()) {     // if there's bytes to read from the client,
        char c = client.read();     // read a byte, then
        Serial.write(c);            // print it out the serial monitor
        if (c == '\n') {            // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"http://localhost:3000/api/"+String(Internet.structure)+"\">here</a> to bip.<br>");
            client.print("Click <a href=\"http://localhost:3000/api/:collection/:id\">here</a> to turn the LED on pin 5 on.<br>");
            client.print("Click <a href=\"/collectionGet\">here</a> to turn the LED on pin 5 off.<br>");


            client.print("<form id='dynamicForm' method='POST'>");
            client.print("<label for='id'>Document ID:</label>");
            client.print("<input type='text' id='id' name='id' value=''>"); 
            client.print("<input type='submit' value='Submit'>");
            client.print("</form>");
            client.print("<script>");
            client.print("document.getElementById('dynamicForm').onsubmit = function(event) {");
            client.print("  event.preventDefault();"); // Prevent default form submission
            client.print("  const id = document.getElementById('id').value;"); 
            client.print("  if (!id) { alert('Please enter a valid ID.'); return; }"); 
            client.print("  this.action = 'http://localhost:3000/api/"+String(Internet.structure)+"/' + encodeURIComponent(id);"); 
            client.print("  this.submit();"); // Submit the form
            client.print("};");
            client.print("</script>");


            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {  // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /00")) {
          digitalWrite(2, HIGH);  // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /api/" + String(Internet.structure))) {
        }
        if (currentLine.endsWith("GET /collectionGet")) {
        }

        if (currentLine.endsWith("GET /")) {
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}

bool CheckLastConne(void) {
  if (WiFi.status() == WL_CONNECTED) {
    return true;
  }
  else if (WiFi.status() == WL_CONNECT_FAILED || WL_CONNECTION_LOST || WL_DISCONNECTED)
  {
    return false;
  }
}