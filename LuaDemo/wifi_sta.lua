wifi.setmode(wifi.STATION)
print(wifi.sta.getip())
--nil
-- setup connect wifi
station_cfg={}
station_cfg.ssid="easy"
station_cfg.pwd="y123456789"
station_cfg.save=true
wifi.sta.config(station_cfg)