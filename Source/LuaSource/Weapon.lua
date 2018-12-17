Spread = 6
Damage = 10

MaxAmmo = 5
Ammo = 5

CurrentTime = 0

function Tick(DeltaSeconds)

	if CurrentTime > 1 and MyWeapon then
		CurrentTime = 0
	end

	CurrentTime = CurrentTime + DeltaSeconds
end
