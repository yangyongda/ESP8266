udpSocket = net.createUDPSocket()
udpSocket:listen(5000)
udpSocket:on("receive", function(s, data, port, ip)
    print(string.format("received '%s' from %s:%d", data, ip, port))
    s:send(port, ip, "echo: " .. data)
end)
port, ip = udpSocket:getaddr()
print(string.format("local UDP socket address / port: %s:%d", ip, port))