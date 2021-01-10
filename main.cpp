#include <unistd.h>
#include <stdexcept>
#include <iostream>

enum class TrafficLight { Red, Yellow, Green };

TrafficLight& operator++(TrafficLight& light) {
    if (light == TrafficLight::Green)
        return light = TrafficLight::Yellow;
    else if (light == TrafficLight::Red)
        return light = TrafficLight::Green;
    else if (light == TrafficLight::Yellow)
        return light = TrafficLight::Red;
    else
        throw std::domain_error("Invalid TraficLight given");
}

void print_traffic_light(TrafficLight& light) {
    if (light == TrafficLight::Green)
        std::cout << "The Light is Green" << std::endl;
    else if (light == TrafficLight::Yellow)
        std::cout << "The Light is Yellow" << std::endl;
    else if (light == TrafficLight::Red)
        std::cout << "The Light is Red" << std::endl;
}

int main() {
    TrafficLight light = TrafficLight::Green;

    while (true) {
        print_traffic_light(light);
        ++light;
        sleep(5);
    }
}