

// TODO, reverse and recreate and replace into src/framework/prediction.cpp
// NOTE: The function below is not my work, this is entirely done by the good
// ol' king of the mountian. ALL!!! credits goto him!
void PredictEntity(CBaseEntity* entity, float projvel) {
    projvel /= 66.666666666f;

    auto currPos = GetCollision(entity).center();
    Vector vel =
        Vector(ent->GetVelocityX(), ent->GetVelocityY(), ent->GetVelocityZ()) /
        66.666666666f;

    float currGravity = gravity;
    float maxGrav = currGravity * 291.666666f;

    for (int i = 0, total = 0; i < 170 && total < 172; i++, total++) {
        // 1 is the minimal amount of lerp which is what I use, TODO: make REAL
        // lerp detection
        auto ticksToHit =
            (1 + gAngle.VecDistance(myWeapon, currPos) / projvel) +
            gHelper.GetPing() / 0.015;
        // what we're doing here is making expensive tick calculations factoring
        // in gravity and distance to ground and the like, but when we get within
        // a tick of simulated accuracy we use the last velocity we used to get a
        // fairly reasonable exact position, then we vischeck it to see if we
        // should progress further (like doing FOV checks)
        if ((ticksToHit - i) > -1.0f && (ticksToHit - i) < 1.0f) {
            Vector absolutePos = currPos + (vel * (ticksToHit - i));
            for (int b = 0; b < 6; b++) {
                Vector currBonePos = absolutePos + Offsets[b];
                Ray.Init(myWeapon,
                         (currBonePos + (currBonePos - myWeapon) * 100.0f));
                gInts.Trace->TraceRay(Ray, MASK_AIMBOT | CONTENTS_HITBOX,
                                      &filterNoPlayer, &tr);

                if (gAngle.VecDistance(tr.end, myWeapon) >=
                    gAngle.VecDistance(currBonePos, myWeapon)) {
                    currTarget = currBonePos;
                    goto fin;  // easy way to break two nested loops :/, as an
                               // alternative this part could be a function
                }
            }
        }
        // Get distance to ground
        Ray.Init(currPos, Vector(currPos.x, currPos.y, currPos.z - 10000.0f));
        gInts.Trace->TraceRay(Ray, MASK_PLAYERSOLID, &filterNoPlayer, &tr);
        float distanceGround = currPos.z - tr.end.z;
        if (distanceGround > 40.0f)
            vel.z -= currGravity;
        else if (distanceGround < 40.0f) {
            currPos.z = tr.end.z + 40.0f;  // TODO: fix this shit
            vel.z = 0;
        }
        if (vel.z < -maxGrav) vel.z = -maxGrav;
        if (oldPos != nullvec) {
            Ray.Init(oldPos, (currPos + (currPos - oldPos) * 100.0f));
            gInts.Trace->TraceRay(Ray, MASK_PLAYERSOLID, &filterNoPlayer, &tr);

            if (gAngle.VecDistance(oldPos, tr.end) <
                gAngle.VecDistance(oldPos, currPos)) {
                vel.x = 0;
                vel.y = 0;
                currPos = oldPos;
                i--;
            }
        }
        predictedTicks[num][i] = currPos;
        oldPos = currPos;
        oldVel = vel;
        currPos += vel;
    }
}
}
}
