
CanShoot = true

MaxAmmo = 5
Ammo = 5

Cooldown = 0.4
CurrentCooldown = 0

RotationSpeed = 1

function Tick(DeltaTime)
	if CurrentCooldown < 0 then
		CanShoot = true
	end

	CurrentCooldown = CurrentCooldown - DeltaTime
end

function OnShoot()
	CanShoot = false
	CurrentCooldown = Cooldown
	Ammo = Ammo - 1
end

function CanWeaponShoot()
	--if Ammo > 0 then
	return CanShoot
	--end
end
