int R = D4;
int G = D5;

void setup() {
    pinMode(R, OUTPUT);
    pinMode(G, OUTPUT);
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", Handler);
}

void loop() {
    Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "wave");
    delay(10000);
    Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "pat");
    delay(10000);
}

void Handler(const char *event, const char *data)
{
    if (strcmp(data, "wave")==0){
        Particle.publish(String::format(event));
        digitalWrite(R, HIGH);
        delay(1000);
        digitalWrite(R, LOW);
        delay(1000);
        digitalWrite(R, HIGH);
        delay(1000);
        digitalWrite(R, LOW);
        delay(1000);
        digitalWrite(R, HIGH);
        delay(1000);
        digitalWrite(R, LOW);
        delay(1000);
    }
    else if (strcmp(data, "pat")==0){
        Particle.publish(String::format(event));
        digitalWrite(G, HIGH);
        delay(500);
        digitalWrite(G, LOW);
        delay(500);
        digitalWrite(G, HIGH);
        delay(500);
        digitalWrite(G, LOW);
        delay(500);
        digitalWrite(G, HIGH);
        delay(500);
        digitalWrite(G, LOW);
        delay(500);
    }
}
