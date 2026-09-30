/*
  LI-FI SOFTWARE SIMULATION - CUSTOM MESSAGE VERSION
  Neenga type panra edhavadhu message-ah transmit pannும்
*/

const int LED_PIN = 9;
const int BIT_DELAY = 100;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
  Serial.println("=== Li-Fi Complete Simulation Ready ===");
  Serial.println("Type any message and press Send to transmit.");
}

void loop() {
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');  // neenga type panra full message edukkum
    message.trim();  // extra spaces/newline remove pannum

    if (message.length() > 0) {
      Serial.println("\n----- TRANSMITTER -----");
      Serial.print("Original Message: ");
      Serial.println(message);

      String bitStream = "";
      encodeAndTransmit(message, bitStream);

      Serial.print("Encoded Bit Stream: ");
      Serial.println(bitStream);

      Serial.println("\n----- RECEIVER -----");
      String decodedMessage = decodeFromBitStream(bitStream);
      Serial.print("Decoded Message: ");
      Serial.println(decodedMessage);

      if (decodedMessage == message) {
        Serial.println("STATUS: Transmission Successful! Data matches.");
      } else {
        Serial.println("STATUS: Error in transmission.");
      }
      Serial.println("========================\n");
    }
  }
}

// TRANSMITTER: character-ah bits-ah convert panni LED blink pannum + bitStream-la store pannum
void encodeAndTransmit(String msg, String &bitStream) {
  for (int i = 0; i < msg.length(); i++) {
    char c = msg[i];
    for (int bit = 7; bit >= 0; bit--) {
      bool bitValue = (c >> bit) & 1;
      digitalWrite(LED_PIN, bitValue ? HIGH : LOW);
      bitStream += bitValue ? "1" : "0";
      delay(BIT_DELAY);
    }
  }
  digitalWrite(LED_PIN, LOW);
}

// RECEIVER: bitStream-ah irundhu characters-ah decode pannum
String decodeFromBitStream(String bits) {
  String result = "";
  for (int i = 0; i < bits.length(); i += 8) {
    if (i + 8 > bits.length()) break;
    byte value = 0;
    for (int j = 0; j < 8; j++) {
      value = (value << 1) | (bits[i + j] - '0');
    }
    result += (char)value;
  }
  return result;
}
