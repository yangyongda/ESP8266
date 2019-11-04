print(wifi.getmode())
wifi.setmode(wifi.SOFTAP)

cfg={}
cfg.ssid="jack"
cfg.pwd="123456789"
cfg.save=true
wifi.ap.config(cfg)