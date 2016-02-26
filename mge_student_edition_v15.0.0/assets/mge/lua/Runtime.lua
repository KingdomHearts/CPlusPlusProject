AddSound("ALL","Prehistoric_Music_Loop",true,0,"NULL",100,false,1,10,"NULL")
loaded = true
function update()
	if(loaded == true) then
		PlaySound("Spider_7.wav")
		Test()
		loaded = false
	end
end

function Test()
Print();
end