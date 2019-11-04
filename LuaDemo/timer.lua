local mytimer = tmr.create()  --create timer

-- register callback 5s
mytimer:register(5000, tmr.ALARM_SINGLE, 
function (t) 
    print("timer trigger")
    t:unregister() --free resource
end)  -- setup timer

mytimer:start()