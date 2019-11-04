--[[
wifi.setmode(wifi.STATION)
station_cfg={}
station_cfg.ssid="yang"
station_cfg.pwd="y123456789"
station_cfg.save=true
wifi.sta.config(station_cfg)
--]]

-- a simple http server
srv=net.createServer(net.TCP) 
srv:listen(80,function(conn) 
    conn:on("receive",function(conn,payload) 
        print(payload) 
        conn:send("<h1> Hello, NodeMcu.</h1>")
    end) 
end)