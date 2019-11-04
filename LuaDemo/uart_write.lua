uart.setup(0, 115200, 8, uart.PARITY_NONE, uart.STOPBITS_1, 0)
print (uart.getconfig(0))
uart.write(0, "Hello, world\n")