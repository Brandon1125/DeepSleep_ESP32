- Desde una ESP32 generamos pulsos cada cierto intervalo de tiempo.
- Desde la otra ESP32 receptora, interpretamos estos pulsos y dependiendo de cual es el intervalo de este pulso, encendemos un led. Principalmente esta ESP32 se encuentra dormida (DeepSleep), pero al recibir un pulso, la ESP32 despierta, por lo cual siempre está pendiente de recibir un pulso.