function int_handle(level, when, eventcount)
    print("level=", level)
    print("when=", when)
    print("eventcount=", eventcount)
end

pin = 1
gpio.mode(pin, gpio.INT)
gpio.trig(pin, "both", int_handle)
