print(wifi.sta.getip())

wifi.setmode(wifi.STATIONAP)

station_cfg={}
station_cfg.ssid="easy"
station_cfg.pwd="y123456789"
station_cfg.save=true
wifi.sta.config(station_cfg)

cfg={}
cfg.ssid="jack"
cfg.pwd="123456789"
cfg.save=true
wifi.ap.config(cfg)