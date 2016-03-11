--Sounds and Music will be loaded in SoundLoader.lua
--Dialog will be loaded in DialogueScript.lua even when it should be Dialog
loaded = true;

state = "reception" -- Next action
trigger = "" -- Action from triggers (ID OF THE OBJECT YOU NAMED IT IN UNITY!)
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

isNotTriggered = true


----Update
function update()
	-- OpenHud()
	-- OpenDoor()
	-- PickUp()
	-- PlaceDown()
  
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
		 if (pickedUpFred == true and trigger == "Door") then
			StopSound("Lobby_Music_Loop.wav")
			PlaySound("Prehistoric_Music_Loop.wav")
			 OpenExhibit()
			 
			 EnterPrehistoric()
ReturnPainting()
DinosaurKill()
DinosaurMeteor()
BirdEvolution()
IceAge() 
CreationofFire()
CavePainting()
SmallCavePainting()
Rebuild_puzzle()
DinosaurSkeleton()
CutUpPuzzle()
EvolutionofMan()
DisplayCasePrehistoric()
PrehistoricFinish()
PrehistoricBanner()
EnterAncientHistory()
ReturnPaintingAncient()
Hercules()
 Olympus()
  Rome()
  Caeser()
  Xiphos()
  Atlantis()
  Helm()
  Shield()
  Pots()
  Maze()
  SevenWonders()
   FallofTroy()
   Gladiator()
   AncientFinish()
   PrehistoricBanner()
   EnterMedieval()
   CrusadeOne()
   CrusadeTwo()
   DisplayCaseMedieval()
   MissingSword()
   Trebuchet()
   Balista()
   HumanSkeleton()
   SkeletonPieces()
   MedievalFinish()
   MedievalBanner()
   EnterArt()
   Mozart()
   Beethoven()
    Rembrandt()
	VanGogh()
	Violin()
	Typewriter()
	VitruvianMan()
	FirstCRT()
	WrightBrothers()
	DaVinci()
	Lightbulb()
	Train()
	Tesla()
	TheLastSupper()
	MonaLisa()
	CreationofAdam()
	SchoolofAthens()
	PictureofDavid()
	FixedAudio()
	ArtFinish()
	ArtBanner()
	EnterModern()
	DisplayCaseModern()
	BerlinWall()
	UBoat()
	Nukes()
	BlackBird()
	WW1()
	WW2()
	CW()
	ModernFinish()
	ModernBanner()
	AllRoomsComplete()
	SecretDoor()
	KillALFRED()
			 
		 end
		if(timer == 10) then
			if (pickedUpFred == true and isNotTriggered == true) then
				NotOpenExhibit()
				isNotTriggered = false
			end
		end
	end
	
end

-- function OpenHud()
	-- if (keyPressed == "F") then
		-- FredHud(true)
    
	-- else
		-- FredHud(false)
	-- end
  -- end
  
 -- function OpenDoor()
	-- if (player_Opendoor) then
		-- OpenDoor("DoorThatYouWant")
	-- end
 -- end
  
-- function PickUp()
	-- if (player_PicksUp) then
		-- Destroy("Object", "World")
		-- Spawn("Object", "Inventory")
	-- end
 -- end
  
-- function PlaceDown()
	-- if (player_PlaceDown) then
		-- Destroy("Object", "Inventory")
		-- Spawn("Object", "World")
	-- end
-- end

--Trigger
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
	RandomDialogAndRepeat("6,7,8")
	SetState("Fred");
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
	SetState("Exhibit");
	pickedUpFred = true
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
	wait(2)
	playDialogueTrack(17)
	playSubtitleScript(17)
	wait(5)
	playDialogueTrack(18)
	playSubtitleScript(18)
	--playSFX(Hammer)
	wait(2)
	playDialogueTrack(19)
	playSubtitleScript(19)
end

-------------------------------------------------------------------

function EnterPrehistoric()
	playDialogueTrack(20)
	playSubtitleScript(20)
	wait(2)
	playDialogueTrack(21)
	playSubtitleScript(21)
	wait(2)
	playDialogueTrack(22)
	playSubtitleScript(22)
	wait(2)
	playDialogueTrack(23)
	playSubtitleScript(23)
	wait(2)
	playDialogueTrack(24)
	playSubtitleScript(24)
	wait(2)
	playDialogueTrack(25)
	playSubtitleScript(25)
	wait(2)
	playDialogueTrack(26)
	playSubtitleScript(26)
	wait(2)
	playDialogueTrack(27)
	playSubtitleScript(27)
end

function ReturnPainting() -- Tutorial
	playDialogueTrack(28)
	playSubtitleScript(28)
end

function DinosaurKill()
	playDialogueTrack(29)
	playSubtitleScript(29)
end

function DinosaurMeteor()
	playDialogueTrack(30)
	playSubtitleScript(30)
end

function BirdEvolution()
	playDialogueTrack(31)
	playSubtitleScript(31)
end

function IceAge()
	playDialogueTrack(32)
	playSubtitleScript(32)
end

function CreationofFire()
	playDialogueTrack(33)
	playSubtitleScript(33)
end

function CavePainting()
	playDialogueTrack(34)
	playSubtitleScript(34)
end

function SmallCavePainting()
	playDialogueTrack(35)
	playSubtitleScript(35)
end

function Rebuild_puzzle()
	playDialogueTrack(36)
	playSubtitleScript(36)
	wait(2)
	playDialogueTrack(37)
	playSubtitleScript(37)
end

function DinosaurSkeleton()
	playDialogueTrack(38)
	playSubtitleScript(38)
end

function CutUpPuzzle()
	playDialogueTrack(39)
	playSubtitleScript(39)
end

function EvolutionofMan()
	playDialogueTrack(40)
	playSubtitleScript(40)
end

function DisplayCasePrehistoric()
	playDialogueTrack(41)
	playSubtitleScript(41)
end

function PrehistoricFinish()
	playDialogueTrack(42)
	playSubtitleScript(42)
	wait(2)
	playDialogueTrack(43)
	playSubtitleScript(43)
end

-------------------------------------------------------------------

function PrehistoricBanner()
	playDialogueTrack(44)
	playSubtitleScript(44)
	wait(2)
	playDialogueTrack(45)
	playSubtitleScript(45)
	wait(2)
	playDialogueTrack(46)
	playSubtitleScript(46)
end

-------------------------------------------------------------------

function EnterAncientHistory()
	playDialogueTrack(47)
	playSubtitleScript(47)
	wait(2)
	playDialogueTrack(48)
	playSubtitleScript(48)
	wait(2)
	--playDialogueTrack(49)
	--playSubtitleScript(49)
end

function ReturnPaintingAncient()
	playDialogueTrack(50)
	playSubtitleScript(50)
end

function Hercules()
	playDialogueTrack(51)
	playSubtitleScript(51)
end

function Olympus()
	playDialogueTrack(52)
	playSubtitleScript(52)
end

function Rome()
	playDialogueTrack(53)
	playSubtitleScript(53)
end

function Caeser()
	playDialogueTrack(54)
	playSubtitleScript(54)
end

function Xiphos()
	playDialogueTrack(55)
	playSubtitleScript(55)
end

function Atlantis()
	playDialogueTrack(57)
	playSubtitleScript(57)
end

function Helm()
	playDialogueTrack(58)
	playSubtitleScript(58)
end

function Shield()
	playDialogueTrack(59)
	playSubtitleScript(59)
end

function Pots()
	playDialogueTrack(60)
	playSubtitleScript(60)
end

function Maze()
	playDialogueTrack(61)
	playSubtitleScript(61)
end

function SevenWonders()
	playDialogueTrack(62)
	playSubtitleScript(62)
end

function FallofTroy()
	playDialogueTrack(63)
	playSubtitleScript(63)
end

function Gladiator()
	playDialogueTrack(64)
	playSubtitleScript(64)
	wait(2)
	playDialogueTrack(65)
	playSubtitleScript(65)	
end

function AncientFinish()
	playDialogueTrack(66)
	playSubtitleScript(66)
	wait(2)
	playDialogueTrack(67)
	playSubtitleScript(67)
end

-------------------------------------------------------------------

function PrehistoricBanner()
	playDialogueTrack(68)
	playSubtitleScript(68)
	wait(2)
	playDialogueTrack(69)
	playSubtitleScript(69)
end

-------------------------------------------------------------------

function EnterMedieval()
	playDialogueTrack(70)
	playSubtitleScript(70)
	wait(2)
	playDialogueTrack(71)
	playSubtitleScript(71)
end

function CrusadeOne()
	playDialogueTrack(72)
	playSubtitleScript(72)
end

function CrusadeTwo()
	playDialogueTrack(73)
	playSubtitleScript(73)
end

function DisplayCaseMedieval()
	playDialogueTrack(74)
	playSubtitleScript(74)
end

function MissingSword()
	playDialogueTrack(75)
	playSubtitleScript(75)
end

function Trebuchet()
	playDialogueTrack(76)
	playSubtitleScript(76)
end

function Balista()
	playDialogueTrack(77)
	playSubtitleScript(77)
end

function HumanSkeleton()
	playDialogueTrack(78)
	playSubtitleScript(78)
end

function SkeletonPieces()
	playDialogueTrack(79)
	playSubtitleScript(79)
end

function MedievalFinish()
	playDialogueTrack(80)
	playSubtitleScript(80)
	wait(2)
	playDialogueTrack(81)
	playSubtitleScript(81)
end

-------------------------------------------------------------------

function MedievalBanner()
	playDialogueTrack(82)
	playSubtitleScript(82)
	wait(2)
	playDialogueTrack(83)
	playSubtitleScript(83)
end

-------------------------------------------------------------------

function EnterArt()
	playDialogueTrack(84)
	playSubtitleScript(84)
	wait(2)
	playDialogueTrack(85)
	playSubtitleScript(85)
end

function Mozart()
	playDialogueTrack(86)
	playSubtitleScript(86)
end

function Beethoven()
	playDialogueTrack(87)
	playSubtitleScript(87)
end

function Rembrandt()
	playDialogueTrack(88)
	playSubtitleScript(88)
end

function VanGogh()
	playDialogueTrack(89)
	playSubtitleScript(89)
end

function Violin()
	playDialogueTrack(90)
	playSubtitleScript(90)
end

function Typewriter()
	playDialogueTrack(91)
	playSubtitleScript(91)
end

function VitruvianMan()
	playDialogueTrack(92)
	playSubtitleScript(92)
end

function FirstCRT()
	playDialogueTrack(93)
	playSubtitleScript(93)
end

function WrightBrothers()
	playDialogueTrack(94)
	playSubtitleScript(94)
end

function DaVinci()
	playDialogueTrack(95)
	playSubtitleScript(95)
end

function Lightbulb()
	playDialogueTrack(96)
	playSubtitleScript(96)
end

function Train()
	playDialogueTrack(97)
	playSubtitleScript(97)
end

function Tesla()
	playDialogueTrack(98)
	playSubtitleScript(98)
end

function TheLastSupper()
	playDialogueTrack(99)
	playSubtitleScript(99)
end

function MonaLisa()
	playDialogueTrack(100)
	playSubtitleScript(100)
end

function CreationofAdam()
	playDialogueTrack(101)
	playSubtitleScript(101)
end

function SchoolofAthens()
	playDialogueTrack(102)
	playSubtitleScript(102)
end

function PictureofDavid()
	playDialogueTrack(103)
	playSubtitleScript(103)
end

function FixedAudio()
	playDialogueTrack(104)
	playSubtitleScript(104)
end

function ArtFinish()
	playDialogueTrack(105)
	playSubtitleScript(105)
	wait(2)
	playDialogueTrack(106)
	playSubtitleScript(106)
end

-------------------------------------------------------------------

function ArtBanner()
	playDialogueTrack(107)
	playSubtitleScript(107)
	wait(2)
	playDialogueTrack(108)
	playSubtitleScript(108)
end

-------------------------------------------------------------------

function EnterModern()
	playDialogueTrack(109)
	playSubtitleScript(109)
	wait(2)
	playDialogueTrack(110)
	playSubtitleScript(110)
end

function DisplayCaseModern()
	playDialogueTrack(111)
	playSubtitleScript(111)
end

function BerlinWall()
	playDialogueTrack(112)
	playSubtitleScript(112)
end

function UBoat()
	playDialogueTrack(113)
	playSubtitleScript(113)
end

function Nukes()
	playDialogueTrack(114)
	playSubtitleScript(114)
end

function BlackBird()
	playDialogueTrack(115)
	playSubtitleScript(115)
end

function WW1()
	playDialogueTrack(116)
	playSubtitleScript(116)
end

function WW2()
	playDialogueTrack(117)
	playSubtitleScript(117)
end

function CW()
	playDialogueTrack(118)
	playSubtitleScript(118)
end

function ModernFinish()
	playDialogueTrack(119)
	playSubtitleScript(119)
	wait(2)
	playDialogueTrack(120)
	playSubtitleScript(120)
end

-------------------------------------------------------------------

function ModernBanner()
	playDialogueTrack(121)
	playSubtitleScript(121)
	wait(2)
	playDialogueTrack(122)
	playSubtitleScript(122)
end

-------------------------------------------------------------------

function AllRoomsComplete()
	playDialogueTrack(123)
	playSubtitleScript(123)
	wait(2)
	playDialogueTrack(124)
	playSubtitleScript(124)
	wait(2)
	playDialogueTrack(125)
	playSubtitleScript(125)
	wait(2)
	playDialogueTrack(126)
	playSubtitleScript(126)
	wait(2)
	playDialogueTrack(127)
	playSubtitleScript(127)
	wait(2)
	playDialogueTrack(128)
	playSubtitleScript(128)
	wait(2)
	playDialogueTrack(129)
	playSubtitleScript(129)
	wait(2)
	playDialogueTrack(130)
	playSubtitleScript(130)
	wait(2)
	playDialogueTrack(131)
	playSubtitleScript(131)
end

function SecretDoor()
	playDialogueTrack(132)
	playSubtitleScript(132)
	wait(5)
	playDialogueTrack(133)
	playSubtitleScript(133)
	wait(5)
	playDialogueTrack(134)
	playSubtitleScript(134)
	wait(5)
	playDialogueTrack(135)
	playSubtitleScript(135)
	wait(5)
	playDialogueTrack(136)
	playSubtitleScript(136)
	wait(5)
	playDialogueTrack(137)
	playSubtitleScript(137)
	wait(5)
	playDialogueTrack(138)
	playSubtitleScript(138)
	wait(5)
	playDialogueTrack(139)
	playSubtitleScript(139)
end

function KillALFRED()
	freeze(true)
	playDialogueTrack(140)
	playSubtitleScript(140)
	wait(5)
	playDialogueTrack(141)
	playSubtitleScript(141)
	wait(5)
	playDialogueTrack(142)
	playSubtitleScript(142)
	wait(5)
	playDialogueTrack(143)
	playSubtitleScript(143)
	wait(5)
	playDialogueTrack(144)
	playSubtitleScript(144)
	wait(5)
	playDialogueTrack(145)
	playSubtitleScript(145)
	wait(5)
	playDialogueTrack(146)
	playSubtitleScript(146)
	wait(5)
	playDialogueTrack(147)
	playSubtitleScript(147)
	freeze(false)
	playDialogueTrack(148)
	playSubtitleScript(148)
	wait(5)
	playDialogueTrack(149)
	playSubtitleScript(149)
	wait(5)
	playDialogueTrack(150)
	playSubtitleScript(150)
end
