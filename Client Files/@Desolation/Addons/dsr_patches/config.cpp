class CfgPatches
{
	class dsr_patches
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"A3_Functions_F","A3_Map_Tanoabuka","dsr_ui"};
		fileName = "dsr_patches.pbo";
		requiredVersion = 0.1;
		author[]= {"Desolation Redux Dev Team"};
	};
};

class CfgFunctions {
	class A2 {
		class Numbers {
			class parseNumber {file = "\dsr_patches\Scripts\parseNumber.sqf";};	
		};
	};
};
class CfgWorlds {
	class CAWorld;
	class Tanoa: CAWorld {
		class AmbientA3 {
			delete Radius440_500;
			delete Radius40_60;
		};
	};
};

class PhysXParams {
	impulseForceRagdollCoef = "300f";
	impulseTorqueRagdollCoef = "300f";
	impulseSpeedRagdollCoef = "9f";
	maxRagdollImpulseForceMagnitude = "1500f";
	maxRagdollImpulseTorqueMagnitude = "450f";
	ragdollHitTime = "0.00001f";
};

class CfgCloudlets {
	class Blood;
	class BloodMist: Blood {
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal_02";
		particleFSNtieth = 8;
		particleFSIndex = 4;
		particleFSFrameCount = 1;
		particleFSLoop = 0;
		lifeTime = "0.2";
		moveVelocity[] = {"(+ inDirX * 2 - surfNormalX / 4) * inSpeed / 300 * 1","( + inDirY * 2 - surfNormalY / 4) * inSpeed / 300 * 1","( + inDirZ * 2 - surfNormalZ / 4) * inSpeed / 300 * 1"};
		rubbing = 0.45;
		size[] = {"(hit/120 + 0.3)","2*(hit/80 + 0.3)"};
		color[] = {{1,0.25,0.25,0.1},{1,0.35,0.35,0.001}};
		randomDirectionPeriod = 0.10000001;
		randomDirectionIntensity = 0.3;
		weight = 0.1;
	};
};

class ImpactEffectsBlood {
	class BloodMist	{
		simulation = "particles";
		type = "BloodMist";
		position[] = {0,0,0.2};
		intensity = 0.5;
		interval = 1;
		lifeTime = 0.7;
		moveVelocity[] = {"(+ inDirX * 2 - surfNormalX / 4) * inSpeed / 200 * 0.05","( + inDirY * 2 - surfNormalY / 4) * inSpeed / 200 * 0.05","( + inDirZ * 2 - surfNormalZ / 4) * inSpeed / 200 * 0.05"};
		MoveVelocityVar[] = {0,0,0};
	};
	class Blood	{
		simulation = "particles";
		type = "Blood";
		position[] = {0,0,0};
		intensity = 0.1;
		interval = 1;
		lifeTime = 0.1;
		size[] = {"(hit/200 + 0.1)","2*(hit/200 + 0.1)"};
		MoveVelocityVar[] = {2,2,2};
	};
	class Blood1 {
		simulation = "particles";
		type = "Blood1";
		position[] = {0,0,0};
		intensity = 0.1;
		interval = 1;
		lifeTime = 0.14999998;
		size[] = {"(hit/200 + 0.1)","2*(hit/200 + 0.1)"};
	};
	class Blood2 {
		simulation = "particles";
		type = "Blood2";
		position[] = {0,0,0};
		intensity = 0.1;
		interval = 1;
		lifeTime = 0.10000001;
		size[] = {"(hit/200 + 0.1)","2*(hit/200 + 0.1)"};
	};
	class Blood3 {
		simulation = "particles";
		type = "Blood3";
		position[] = {0,0,0};
		intensity = 0.1;
		interval = 1;
		lifeTime = 0.10000001;
		size[] = {"(hit/200 + 0.1)","2*(hit/200 + 0.1)"};
	};
	class BloodUnderwater1 {
		simulation = "particles";
		type = "BloodUnderwater1";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.4;
	};
};