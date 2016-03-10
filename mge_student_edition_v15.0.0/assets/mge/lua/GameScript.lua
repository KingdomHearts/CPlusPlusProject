--playSubtitleScript = Dialog script
--playSubtitleScript = Audio file

AddSound("","Mono_Sample.wav",true,0,"NULL",100,true,1,10,"0,3,-10")
AddSound("","Lobby_Music_Loop.wav",true,0,"NULL",100,true,1,10,"0,3,-10")
AddSound("","Medieval_Music_Loop.wav",true,0,"NULL",100,true,1,10,"0,3,-10")
AddSound("","Prehistoric_Music_Loop.wav",true,0,"NULL",100,true,1,10,"0,3,-10")
loaded = true;

state = "reception"
keyPressed = ""
mouseIsClicked = true
timer = 0 -- maybe also done by C++ addseconds
player_Opendoor = false
player_PicksUp = false
player_PlaceDown = false
goingToExhibit = false
pickedUpFred = false
--goingToExhibitSeconds = 0 -- maybe also done by C++ addseconds

--changeable through C++
eventFred = ""
player_Opendoor = false

--Update
function update()
	if(loaded == true) then
		PlaySound("Mono_Sample.wav")
		loaded = false
	end
  OpenHud()
  OpenDoor()
  PickUp()
  PlaceDown()

	if(state == "reception")then
		PlaySound("Lobby_Music_Loop.wav")
		BeginGame()
	end

	if(state == "Fred") then
	StartTimer(10)
		if(keyPressed == "Y") then
		keyPressed = "";
		timer = 0;
			PickedUpFred()
		end
		if (keyPressed == "") then
			if (timer > 9) then
			NotPickupFRED()
			end
		end
	end
	if(state == "Exhibit") then
		if(pickedUpFred == true) then
		StartTimer(10)
		end
		 if (pickedUpFred == true and goingToExhibit == true) then
			StopSound("Lobby_Music_Loop.wav")
			PlaySound("Prehistoric_Music_Loop.wav")
			 OpenExhibit()
		 end
		if (pickedUpFred == true and goingToExhibit == false) then
			if(timer > 9) then
				NotOpenExhibit()
			end
		end
	end
end

function OpenHud()
	if (keyPressed == "F") then
		FredHud(true)

	else
		FredHud(false)
	end
  end

 function OpenDoor()
	if (player_Opendoor) then
		OpenDoor("DoorThatYouWant")
	end
 end

function PickUp()
	if (player_PicksUp) then
		Destroy("Object", "World")
		Spawn("Object", "Inventory") -- PickUpModel ("Object")
	end
 end

function PlaceDown()
	if (player_PlaceDown) then
		Destroy("Object", "Inventory")
		Spawn("Object", "World") --PlaceModel ("Object");
	end
end

 -- Trigger
function BeginGame()
	freeze(true)
	playDialogueTrack(1)
	playSubtitleScript(1)
	wait(2)
	playDialogueTrack(2)
	playSubtitleScript(2)
	wait(2)
	playDialogueTrack(3)
	playSubtitleScript(3)
	wait(2)
	playDialogueTrack(4)
	playSubtitleScript(4)
	wait(2)
	playDialogueTrack(5)
	playSubtitleScript(5)
	--freeze(false)
	SetState("Fred");
end

function NotPickupFRED()
	playDialogueTrack(6)
	playSubtitleScript(6)
	wait(2)
	playDialogueTrack(7)
	playSubtitleScript(7)
	wait(2)
	playDialogueTrack(8)
	playSubtitleScript(8)
	RandomDialogAndRepeat("6,7,8")
	SetState("Exhibit");
end

function PickedUpFred()
	playDialogueTrack(9)
	playSubtitleScript(9)
	wait(2)
	playDialogueTrack(10)
	playSubtitleScript(10)
	wait(2)
	playDialogueTrack(11)
	playSubtitleScript(11)
	wait(2)
	playDialogueTrack(12)
	playSubtitleScript(12)
	pickedUpFred = true
	SetState("Exhibit");
	goingToExhibit = true
end

function NotOpenExhibit()
	playDialogueTrack(13)
	playSubtitleScript(13)
	wait(2)
	playDialogueTrack(14)
	playSubtitleScript(14)
end

function OpenExhibit()
	playDialogueTrack(15)
	playSubtitleScript(15)
	wait(2)
	playDialogueTrack(16)
	playSubtitleScript(16)
	Load("Prehistoric")
end
