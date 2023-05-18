#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>


const char *ssid = "Freebox-452891";
const char *password = "Gh9$hs2:";

void setupWifi()
{
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void getDateTime()
{
    String serverPath = "https://timeapi.io/api/Time/current/zone?timeZone=Europe/Paris";
    HTTPClient http;
    http.begin(serverPath.c_str());
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0)
    {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
        DynamicJsonDocument doc(256);
        deserializeJson(doc, payload);
        int year = doc["year"];
        int month = doc["month"];
        int day = doc["day"];
        int hour = doc["hour"];
        int minute = doc["minute"];
        int seconds = doc["seconds"];

        //rtc.setTime(seconds, minute, hour, day, month, year);
        
        Serial.println((String)"Date = " + year + "/" + month + "/" + day + " " + hour + ":" + minute + ":" + seconds);
        http.end();
    }
    else
    {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
        http.end();
    }
}