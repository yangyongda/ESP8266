if not tmr.create():alarm(5000, tmr.ALARM_SINGLE, function()
  print("5s alarm")
end)
then
  print("error")
end