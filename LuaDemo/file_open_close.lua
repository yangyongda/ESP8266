-- open file in flash:
if file.open("init.lua") then
  print(file.read())
  file.close()
end

-- or with full pathspec
if file.open("/FLASH/init.lua") then
  print(file.read())
  file.close()
end
