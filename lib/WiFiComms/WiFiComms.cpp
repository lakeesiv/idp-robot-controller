#include <WiFiComms.h>
#include <ArduinoHttpClient.h>
#include <WiFiNINA.h>
#include <Arduino.h>


void WiFiComms::Connect() {
	while (wl_status != WL_CONNECTED) {
		Serial.print("Attempting to connect to Network named: ");
		Serial.println("LAPTOP-HI8GMNAK 7424");

		// Connect to WPA/WPA2 network:
		wl_status = WiFi.begin("LAPTOP-HI8GMNAK 7424", "021E=19t");
	}
	// print the SSID of the network you're attached to:
	Serial.print("SSID: ");
	Serial.println(WiFi.SSID());

	// print your WiFi shield's IP address:
	IPAddress ip = WiFi.localIP();
	Serial.print("IP Address: ");

	Serial.println(ip);
	client.println();
}

void WiFiComms::Get(String endpoint) {
	client.beginRequest();
	String base_url = "http://" + String("192.168.137.1") + ":" + String(6969);
	client.get(base_url + endpoint);
	client.endRequest();
}

void WiFiComms::SendCoords(float x, float y) {
	Get("/coords/" + String(x) + "/" + String(y));
}