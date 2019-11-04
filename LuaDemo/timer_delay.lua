pin = 0
gpio.mode(pin, gpio.OUTPUT) -- pin config to output mode
gpio.write(pin, gpio.LOW)  -- led light

tmr.delay(5000000)      --5000000us = 5s
gpio.write(pin, gpio.HIGH) 