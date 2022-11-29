// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECT_API AWeapon : public AItem
{
	GENERATED_BODY()
	
public:
	AWeapon();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Skeletal Mesh")
	class USkeletalMeshComponent* SkeletalMesh;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void Equip(class AMain* Char);
};
