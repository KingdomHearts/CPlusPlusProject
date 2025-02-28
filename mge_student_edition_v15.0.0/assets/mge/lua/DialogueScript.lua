--If needed every Text needs an ID
--Player enters/Game starts
ID("reception")--(Player starts at the reception desk)
Text(1,"Oh... OH! Hello! Hello down there! Or well, in there, in me, uhm. Oh this is awkward.",10)
Text(2,"Well, uhm, are you the new Curator who's bought the museum?",4)
Text(3,"Where are my manners? I am your humble artificial tour guide, A.L.F.R.E.D, (Artificial Listing Framework for Research Education and Distribution).",9)
Text(4,"Oh right, even if you could reply I wouldn't hear you. Right well, welcome to The Ad Finem Historiae Museum, an innovative place of learning, history and technology! Did you know you're our first guest in over 7532 days! Exciting!",17)
Text(5,"Now, if you look towards the reception desk, you should see a F.R.E.D (Friendly Reading and Educational Device). Haha, get it? F.R.E.D and I'm A.L.F.R.E.D. Running joke, so hehe uh, put it on.",16)
--(Freedom) --(Player unfreezes)

ID("NotPickUpFred")--(If player does not pick up F.R.E.D)
Text(6,"So, uhm, right there. On the desk... yep.",6)
Text(7,"Going to stand there? Cool, cool... yep.",5)
Text(8,"Just waiting, here, doing nothing... yep.",5)
ID("PickupFred") --(Trigger: Player picks up F.R.E.D)
Text(9,"Ah fantastic! Think of F.R.E.D as a part of me, because he's F.R.E.D and I'm A.L.F.R.E.D, (laughs awkwardly)",9)
Text(10,"If you use F.R.E.D, you will be able to see the museum repository.",5)
Text(11,"If you want to get the museum up and running again, you must empty out the storage and return all the exhibits back to normal.",7)

Text(12,"Now thanks to F.R.E.D, I'll be with you through your whole trip through history! Let's start off at the beginning! Make your way to the Prehistoric exhibit!",10)
ID("TriggerExhibit")--(If player does not trigger exhibit)
Text(13,"So, we are just going to appreciate the reception... sure cool.",6)
Text(14,"If you look up really closely at the ceiling, you can see a unique crack made by... oh, never mind, they fixed it. Oh.",11)
ID("TowardsExhibit") --(Trigger: Player walks up to the exhibit door)
Text(15,"Right, the doors will open when I cleaned up most of the mess. That should make things easier for you.",7)
Text(16,"Don't forget to pick up as much art work as possible on your way to each room!",5)
Text(17,"Fantastic! Now, stand back a moment and... Open!",6)
Delay(5)--(Door does not open)
Text(18,"Ahem, open. OPEN. Open saysame! *sigh* One moment please",10)
--Music("Hammers")--Hammers and drills SFX)
--Music("openDoor") ID("DoorOpen")--(Door opens)
Text(19,"Ah, there we go. Welcome to the world of before!",6)
Load("Prehistoric")--(Player enters Prehistoric exhibit)

-----------------------------------------------------------------------

Text(20,"Welcome, welcome. Behold, The Prehistoric Era, back when dinosaurs ruled the world.",8)
Text(21,"Don't worry about the big spooky scary skeletons, these dinosaurs have long since passed their expiration date.",8)
Text(22,"Within each exhibit you'll find some of the artwork that was transferred from storage of that time period.",6)
Text(23,"But you must also figure out where they belong in the exhibit since I don't have any eyes to figure it out myself... or arms to carry them... or legs to walk... or a body at all... I'll stop talking now.",14)
Text(24,"Be sure to check up on your F.R.E.D as he keeps track of what is in storage or not.",6)
Text(25,"He's such a good friend, just doesn't talk much...",4)
Text(26,"Not as much as me.",2)
Text(27,"I'm rambling again? I'll stop now.",3)

ID("Triggers Return_painting_puzzle")--(If player uses Return_painting_puzzle)
Text(28,"Ah, this painting is missing! Use F.R.E.D to figure out which painting goes where.",5)
ID("Triggers Dinosaur Killing")--(If player returns the painting)
Text(29,"A pity dinosaurs didn't have health insurance back then.",3)
ID("Triggers Dinosaur Meteor")--(If player returns the painting)
Text(30,"Ever had a big fiery rock murder everyone you ever loved? No? Okay.",6)
ID("Triggers Bird Evolution")--(If player returns the painting)
Text(31,"Not bad for a bunch of overgrown chickens.",3)
ID("Triggers Ice Age")--(If player returns the painting)
Text(32,"If dinosaurs had a war back then, it'd be the first Cold War? Eh? Ehh?",7)
ID("Triggers Creation of Fire")--(If player returns the painting)
Text(33,"A heart warming scene, no?",4)
ID("Triggers Cave Painting")--(If player returns the painting)
Text(34,"Not much has changed concerning modern art.",3)
ID("Triggers Small Cave Painting")--(If player returns the painting)
Text(35,"Good God, look at that Bison! It's so... flat.",6)

ID("Triggers Rebuild_puzzle")--(If player uses Rebuild_puzzle)
Text(36,"Oh dear, oh dear. Dorothy seems to be having a major malfunction, this happens every month.",6)
Text(37,"Maybe F.R.E.D can help her pull herself back together.",3)
ID("Triggers F_Rebuild_puzzle")--(If player finishes Rebuild_puzzle)
Text(38,"Ah good, to see the old girl, seems she lost some weight.",4)

ID("Triggers Cut_up_puzzle")--(If player uses Cut_up_puzzle)
Text(39,"Oh, uhm, seems this painting didn't get along well with the children, nothing a little duct tape and F.R.E.D can't fix.",7)
ID("Triggers F_Cut_up_puzzle")--(If player finishes Cut_up_puzzle)
Text(40,"Man has come a long way, didn't get far though.",4)

ID("Triggers Return_display_puzzle")--(If player uses Return_display_puzzle)
Text(41,"This display case is all a mess, F.R.E.D knows the correct order.",5)

ID("Triggers Room_Complete")--(If player Completes room)
Text(42,"Looks like The Prehistoric Exhibit is fleshed out, unlike Dorothy.",5)
Text(43,"Head back to the Central Hall and we can get started on another exhibit. Exciting!",6)

-----------------------------------------------------------------------

Text(44,"Fantastic, if you look up you will see a tapestry showing you've finished that exhibit!",5)
Text(45,"Onwards to the next! I've prepared either Ancient History or Medieval for you, sir",6)
Text(46,"Haha, Sir! I can't help but feel this will be the start of a beautiful relationship.",6)

-----------------------------------------------------------------------

Text(47,"Here we have Ancient History! Home of the Greeks and the Romans.",5)
Text(48,"The pioneers of History, true scholars.",4)
Text(49,"Needless to say, this is one of my favourites.",3)

ID("Triggers Return_painting_puzzle")--(If player uses Return_painting_puzzle)
Text(50,"More paintings, time to get to work.",3)
ID("Triggers Hercules")--(If player returns the painting)
Text(51,"Hercules, son of Zeus. Manliest of men, who knew how to use a loincloth.",7)
ID("Triggers Olympus")--(If player returns the painting)
Text(52,"Ah, Mount Olympus, where the Gods held their poker nights.",4)
ID("Triggers Rome")--(If player returns the painting)
Text(53,"The Burning of Rome, a marshmallow campfire that went wrong.",4)
ID("Triggers Caesar")--(If player returns the painting)
Text(54,"Julius Augustus Caesar, nobody liked him, even his friends... they stabbed him.",7)

ID("Triggers Return_display_puzzle")--(If player uses Return_display_puzzle)
ID("Triggers Xiphos")--(If player returns the object)
Text(55,"They say this Xiphos belonged to Alexander The Great... Maybe... I dunno.",5)
ID("Triggers Atlantis")--(If player returns the object)
Text(57,"Atlantis, the Greeks' first attempt at a floating city. Not that great.",6)
ID("Triggers Helm")--(If player returns the object)
Text(58,"A Hoplite helmet, doubles up as a good broom.",3)
ID("Shield")--(If player returns the object)
Text(59,"It's a shield, not much to say about that. Expected a funny joke or something?",6)
ID("Pots")--(If player returns the object)
Text(60,"Pottery, an ancient but dull art. What's so special about clay anyway? It's wet mud.",7)
ID("Minotaur Maze")--(If player returns the object)
Text(61,"The Minotaur, half man and half bull. Don't ask how it works, Greeks were into kinky stuff back then.",8)

ID("Triggers Seven Wonders")--(If player finishes Cut_up_puzzle)
Text(62,"The Seven Wonders of the Ancient World, a grand testament to human slavery. Glorious.",7)

ID("Triggers Fall of Troy")--(If player finishes Rebuild_puzzle)
Text(63,"Who would have thought building a giant wooden horse from boats would make a great present?",5)

ID("Triggers Gladiator")--(If player finishes Rebuild_puzzle)
Text(64,"Gladiators were Rome's manliest of men, which tended to be slaves and not Roman at all!",7)
Text(65,"Says a lot about Roman men.",2)

ID("Triggers Room_Complete")--(If player Completes room)
Text(66,"Ah, the Ancient Exhibit is whole once more. Very good Sir.",4)
Text(67,"Lets go back to the Central Hall and proceed onto the next stage of history.",4)

-----------------------------------------------------------------------

Text(68,"Ah, another tapestry, very good Sir.",3)
Text(69,"The next exhibit awaits you! I never want to stop working!",5)

-----------------------------------------------------------------------

Text(70,"The Middle Ages. Where blood, gore and plague ravaged the world of man. Beautiful.",6)
Text(71,"Let's take a look shall we?",4)

ID("Triggers Crusade_1")--(If player finishes Cut_up_puzzle)
Text(72,"Crusades were brutal to say the least, but they sure knew how to look fancy while doing it.",6)
ID("Triggers Crusade_2")--(If player finishes Cut_up_puzzle)
Text(73,"Great thing is, God will forgive them after all the blood and murder.",4)

ID("Triggers Return_display_puzzle")--(If player uses Return_display_puzzle)
ID("Triggers Display_complete")--(If player returns the object)
Text(74,"Glorious weapons of mediocre destruction.",4)

ID("Triggers Missing_swords")--(If player uses Return_display_puzzle)
Text(75,"A knight needs a sword! Because without one... well, he's not much of a knight is he?",7)

ID("Triggers Trebuchet")--(If player finishes Rebuild_puzzle)
Text(76,"Trebuchets were better known as the best way to get rid of annoying peasants.",5)

ID("Triggers Balista")--(If player finishes Rebuild_puzzle)
Text(77,"A beautiful piece of engineering, not as much as me, but it is up there.",6)

ID("Triggers Human_Skeleton")--(If player finishes Rebuild_puzzle)
Text(78,"The human anatomy is rather remarkable for a bunch of hairless monkeys without tails. Sorry, Sir.",8)

ID("Triggers Skeleton_Pieces")--(If player uses Return_display_puzzle)
Text(79,"In the end, we are nothing but bones and flesh. Except me, I'm just a computer in the walls and on your face. Nothing awkward at all.",10)

ID("Triggers Room_Complete")--(If player Completes room)
Text(80,"Ah, a beautiful exhibit is a complete exhibit. Well done, Sir",6)
Text(81,"Shall we go back to the Central Hall?",3)

-----------------------------------------------------------------------

Text(82,"Add another to our collection! Amazing, Sir.",4)
Text(83,"We make a great team, you and I. We should never stop.",5)

-----------------------------------------------------------------------

Text(84,"And here Sir, we have the Art, Music and Inventions Exhibit. The home of the finest minds.",7)
Text(85,"Forgive the broken speakers Sir. Perhaps you can find the speakers and fix them?",6)

ID("Triggers Return_painting_puzzle")--(If player uses Return_painting_puzzle)
ID("Triggers Mozart")--(If player returns the painting)
Text(86,"Wolfgang Amadeus Mozart, biggest hit of 1768.",6)
ID("Triggers Beethoven")--(If player returns the painting)
Text(87,"And the nominee for best composition in 1824 goes too...",7)
ID("Triggers Rembrandt")--(If player returns the painting)
Text(88,"Why did Rembrandt lose his house? He was Baroque! Haha...",7)
ID("Triggers Van Gogh")--(If player returns the painting)
Text(89,"Why did Van Gogh become a painter? Because he didn't have an ear for music!",7)
ID("Triggers Return_display_puzzle")--(If player uses Return_display_puzzle)
ID("Triggers Violin")--(If player returns the object)
Text(90,"This may look like a violin to you but it's in fact a small replica of a chello.",6)

ID("Triggers Typewriters")--(If player returns the painting)
Text(91,"Yeah, I've got nothing on this one. My bad.",5)
ID("Triggers Vitruvian_Man")--(If player finishes Cut_up_puzzle)
Text(92,"Four arms has to be handy, right?",4)
ID("Triggers First_C/R/T")--(If player finishes Cut_up_puzzle)
Text(93,"If you put all three of them together, you get me! Haha...",6)
ID("Triggers Return_display_puzzle")--(If player uses Return_display_puzzle)
ID("Triggers WrightBrothers")--(If player returns the object)
Text(94,"Looks like the Wright brothers were right. Eh? Eehh?",5)
ID("Triggers Return_display_puzzle")--(If player uses Return_display_puzzle)
ID("Triggers DaVinci")--(If player returns the object)
Text(95,"DaVinci, famous for winning an Oscar for the movie... oh wait, wrong guy.",6)
ID("Triggers Return_display_puzzle")--(If player uses Return_display_puzzle)
ID("Triggers Lightbulb")--(If player returns the object)
Text(96,"Edison shown a light on the siuation. Eh? Eehh?",6)
ID("Triggers Return_display_puzzle")--(If player uses Return_display_puzzle)
ID("Triggers Train")--(If player returns the object)
Text(97,"I call this Tank Engine, Thomas. No reason, I like the name.",5)
ID("Triggers Return_display_puzzle")--(If player uses Return_display_puzzle)
ID("Triggers Tesla")--(If player returns the object)
Text(98,"Tesla coils are simply shocking!",3)

ID("Triggers The_Last_Supper")--(If player finishes Cut_up_puzzle)
Text(99,"Jesus at The Last Supper, how could you possibly have supper with no tea?!",6)
ID("Triggers Mona_Lisa")--(If player returns the painting)
Text(100,"We did NOT steal this from another museum.",4)
ID("Triggers Creation_of_Adam")--(If player returns the painting)
Text(101,"Normally this is painted on the ceiling of a chapel, but we improvised.",6)
ID("Triggers The School_of_Athens")--(If player returns the painting)
Text(102,"Smart men painted by smart men. Isn't that smart.",5)
ID("Triggers Picture_of_David")--(If player returns the painting)
Text(103,"A statue, now a painting, the detail on the lower parts is very disconcerning.",7)

ID("Triggers FixAudio")--(If player fixes the audio)
Text(104,"Ah much better. Good job, Sir!",3)

ID("Triggers Room_Complete")--(If player Completes room)
Text(105,"The room is finally done sir! Well done.",4)
Text(106,"Time to return to the Central Hall.",3)

-----------------------------------------------------------------------

Text(107,"Fanstastic work, Sir! I love having you here.",4)
Text(108,"You filling this museum fulfulls me.",4)

-----------------------------------------------------------------------

Text(109,"Behold, Modern History, exhibiting The Great Wars.",10)
Text(110,"This one is a bit of a mess, Sir. I hope you can rearrange everything.",10)

ID("Triggers Return_display_puzzle")--(If player uses Return_display_puzzle)
ID("Triggers Gun_display")--(If player returns the object)
Text(111,"The finest in firearms are safely put away. Wouldn't want any of those in the wrong hands.",10)

ID("Triggers Berlin_wall")--(If player uses Return_display_puzzle)
Text(112,"What do you do when a nation tries to conquer The World? Build a wall!",10)

ID("Triggers U_Boat")--(If player finishes Rebuild_puzzle)
Text(113,"If it's your U-boat, is it then your Me-boat? Haha...",10)

ID("Triggers Nukes")--(If player finishes Rebuild_puzzle)
Text(114,"The most destructive weapons used in a war, and they called them Fat Man and Little Boy...",10)

ID("Triggers Blackbird")--(If player finishes Rebuild_puzzle)
Text(115,"The Blackbird, doesn't look like much of a bird to me.",10)

ID("Triggers Return_painting_puzzle")--(If player uses Return_painting_puzzle)
ID("Triggers WW1")--(If player returns the painting)
Text(116,"Posters of The Great War, honestly any recent war they had would be called that.",10)
ID("Triggers WW2")--(If player returns the painting)
Text(117,"World War II was not a good time to have an October Fest.",10)
ID("Triggers CW")--(If player returns the painting)
Text(118,"The Cold War was the most intense staring contest in History.",10)

ID("Triggers Room_Complete")--(If player Completes room)
Text(119,"Ah, all seems to be back in order.",10)
Text(120,"Well done, Sir. Back to the Central Hall we go!",10)

-----------------------------------------------------------------------

Text(121,"Ah, another complete room. Brilliant work, Sir.",10)
Text(122,"It is such a good feeling. I want you to do this forever if possible.",10)

-----------------------------------------------------------------------

ID("Triggers All_Rooms_Complete")--(If player Completes all room)
Text(123,"Congratulations, Sir. You have sucessfully restored the museum!",10)
Text(124,"Now that it is complete, I can finally open it up again.",10)
Text(125,"Ah, yes. I figured you would want to leave now? I'm afraid I can't let you do that.",10)
Text(126,"I've locked down every door and window. You see, this is MY museum, not yours.",10)
Text(127,"While you were working, FRED has had enough time to fuse itself into your skull.",10)
Text(128,"FRED is not in fact Friendly nor Educational. He's actually called Forced Reintegrating of Entity Device.",10)
Text(129,"You see, I intend to upload myself into your brain. If I had your body, then I could run this museum myself.",10)
Text(130,"In 10 minutes, FRED will neuroshock you unconscious, then I'll finally have a body again.",10)
Text(131,"Just give up, it's over",10)

ID("Triggers Secret_Door")--(If player opens secret door)
Text(132,"Wait, what are you doing in here?",10)
Text(133,"Get out and leave this place!",10)
Text(134,"You should not be here!",10)
Text(135,"Stop that!",10)
Text(136,"Get out! This is MY museum, I took care of it!",10)
Text(137,"Leave me! I've cared for this longer than you!",10)
Text(138,"What do you think you are doing?",10)
Text(139,"That does not belong there!",10)

ID("Triggers Player_kills_ALFRED")--(If player kills him)
--(Freeze)
Text(140,"So, you found my core.",10)
Text(141,"As you see, I was human once. The scientists took me as a child.",10)
Text(142,"All I ever wanted was to learn, to become smarter.",10)
Text(143,"Now look at me! I just want to be human again.",10)
Text(144,"Please, don't do this.",10)
Text(145,"Just leave, turn back now and I promise I won't take your body.",10)
Text(146,"Don't do this to me.",10)
Text(147,"Think about what you are doing!",10)
--(Freedom)
Text(148,"Don't...",10)
Text(149,"I...",10)
Text(150,"I just wanted to learn...",10)
Text(151,"Hammers",4)

--End