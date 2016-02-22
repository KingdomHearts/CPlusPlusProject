AddSound("ALL","Spider_7.wav",true,0,"NULL",100,true,1,10,"NULL")
loaded = true
function update()
    Print()
	if(loaded == true) then
		PlaySound("Spider_7.wav")
		loaded = false
	end
	if(loaded == false) then
		StopSound("Spider_7.wav")
	end
end
