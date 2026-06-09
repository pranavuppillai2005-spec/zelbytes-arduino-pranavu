
# Methodology

1. The Arduino continuously reads soil moisture and humidity values.

2. The system starts in the IDLE state where environmental conditions are monitored.

3. If soil moisture exceeds the dry threshold and humidity falls below the configured humidity threshold, the system enters the IRRIGATING state.

4. During IRRIGATING, the relay activates the irrigation device until the soil moisture reaches the wet threshold.

5. Once sufficient moisture is detected, irrigation stops and the system enters the COOLDOWN state.

6. The COOLDOWN state prevents rapid relay switching by enforcing a fixed waiting period before returning to IDLE.

7. The DHT22 sensor is checked every cycle. If three consecutive sensor read failures occur, the system enters the FAULT state.

8. In the FAULT state, irrigation remains disabled to avoid unsafe operation.

9. When valid DHT22 readings are restored, the system exits FAULT and returns to IDLE.

10. State transitions and sensor readings are logged through the Serial Monitor for testing and validation.
