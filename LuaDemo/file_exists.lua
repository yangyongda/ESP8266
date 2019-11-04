files = file.list()
if files["device.config"] then
    print("Config file exists")
else
    print("file not exists")
    file.open("device.config", "w") -- create file if file not exist
end

if file.exists("device.config") then
    print("Config file exists")
end