MaxTimer = 120
CurrentTimer = 120
LevelStart = false

function LevelTimer(DeltaTime)
	if LevelStart = true and CurrentTimer > 0 and CurrentTimer <= MaxTimer then
		CurrentTimer = CurrentTimer - DeltaTime
	end
end
