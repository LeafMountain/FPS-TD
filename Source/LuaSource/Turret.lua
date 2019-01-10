
CanShoot = false

MaxAmmo = 15
Ammo = 15

Cooldown = 0.5
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
