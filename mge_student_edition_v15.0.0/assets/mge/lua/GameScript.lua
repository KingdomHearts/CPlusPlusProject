--playSubtitleScript = Dialog script
--playSubtitleScript = Audio file

AddSound("ALL","Lobby_Music_Loop.wav",true,0,"NULL",100,false,1,10,"NULL")
loaded = true;

state = "reception"
pickedUpFred = false
pickedUpFredSeconds = 0 -- maybe also done by C++ addseconds
player_Opendoor = false
player_PicksUp = false
player_PlaceDown = false
goingToExhibit = false
goingToExhibitSeconds = 0 -- maybe also done by C++ addseconds

--changeable through C++
eventFred = ""
player_Opendoor = false

--Update
function update()
	if(loaded == true) then
		PlaySound("Lobby_Music_Loop.wav")
		loaded = false
	end
  OpenHud()
  OpenDoor()
  PickUp()
  PlaceDown()

	if(state == "reception")then
		BeginGame()
	end

	if(state == "Fred") then
		if(pickedUpFred == true) then
			pickedUpFred()
		end
		if (pickedUpFred == false) then
		pickedUpFredSeconds = pickedUpFredSeconds + 1
			if (pickedUpFredSeconds > 9) then
			NotPickupFRED()
			end
		end
	end
	if(state == "Exhibit") then
		 if (pickedUpFred == true and goingToExhibit == true) then
			 OpenExhibit()
		 end
		if (pickedUpFred == true and goingToExhibit == false) then
			goingToExhibitSeconds = goingToExhibitSeconds + 1
			if(goingToExhibitSeconds > 9) then
				NotOpenExhibit()
			end
		end
	end
end

function OpenHud()
	if (eventFred == "F") then
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
	freeze(false)
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
	SetState("Exhibit");
end

function PickupFred()
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
	SetState("Exhibit");
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
