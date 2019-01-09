Spread = 6
Damage = 10

SingleDamage = 15
SingleSpread = 3

SlowDamage = 5
SlowSpread = 3

SplashDamage = 10
SplashSpread = 10

MaxAmmo = 15
Ammo = 15

CurrentTime = 0

function Tick(DeltaSeconds)

	if CurrentTime > 1 and MyWeapon then
		CurrentTime = 0
	end

	CurrentTime = CurrentTime + DeltaSeconds
end
