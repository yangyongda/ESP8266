--[[
wifi.setmode(wifi.STATION)
station_cfg={}
station_cfg.ssid="yang"
station_cfg.pwd="y123456789"
station_cfg.save=true
wifi.sta.config(station_cfg)
--]]

--[[
srv = net.createConnection(net.TCP, 0)
srv:on("receive", function(sck, c) print(c) end)
-- Wait for connection before sending.
srv:on("connection", function(sck, c)
  -- 'Connection: close' rather than 'Connection: keep-alive' to have server
  -- initiate a close of the connection after final response (frees memory
  -- earlier here), https://tools.ietf.org/html/rfc7230#section-6.6
  sck:send("GET /get HTTP/1.1\r\nHost: httpbin.org\r\nConnection: close\r\nAccept: */*\r\n\r\n")
end)
srv:connect(80,"httpbin.org")
--]]

-- A simple http client
conn=net.createConnection(net.TCP, 0) 
conn:on("receive", function(conn, pl) print(pl) end)
conn:connect(80,"121.41.33.127")
conn:send("GET / HTTP/1.1\r\nHost: www.nodemcu.com\r\n"
    .."Connection: keep-alive\r\nAccept: */*\r\n\r\n")