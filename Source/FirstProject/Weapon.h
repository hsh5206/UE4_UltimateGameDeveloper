// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponState :uint8
{
	EWS_Pickup UMETA(DisplayName="PickUp"),
	EWS_Equipped UMETA(DisplayName = "Equipped"),
	EWS_MAX UMETA(DisplayName = "DefaultMax")
};

/**
 * 
 */
UCLASS()
class FIRSTPROJECT_API AWeapon : public AItem
{
	GENERATED_BODY()

public:
	AWeapon();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item")
	EWeaponState WeaponState;
	FORCEINLINE void SetWeaponState(EWeaponState state) { WeaponState = state; }
	FORCEINLINE EWeaponState GetWeaponState() { return WeaponState; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Itme | Particles")
	bool bWeaponParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Itme | Sound")
	class USoundCue* OnEquipSound;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SkeletalMesh")
	class USkeletalMeshComponent* SkeletalMesh;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void Equip(class AMain* Char);
};
