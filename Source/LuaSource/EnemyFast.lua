Speed = 400
Health = 10

function ModifyHealth( Value )
    Health = Health + Value
end

function GetHealth()
    return Health
end

function GetSpeed()
    return Speed
end

function IsDead()
    return Health <= 0
end