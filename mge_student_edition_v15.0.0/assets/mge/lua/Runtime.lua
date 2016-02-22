AddSound("ALL","Spider_7.wav",true,0,"NULL",100,true,1,10,"NULL")
loaded = true
function update()
	if(loaded == true) then
		PlaySound("Spider_7.wav")
		Test()
		loaded = false
	end
	if(loaded == false) then
		StopSound("Spider_7.wav")
	end
end

function Test()
Print();
end