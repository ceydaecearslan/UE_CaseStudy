// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

struct FOnAttributeChangeData;
class UAbilitySystemComponent;
class UPlayerAttributeSet;

UCLASS()
class CASESTUDY_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	APlayerCharacter();

	FORCEINLINE UAbilitySystemComponent* GetAbilitySystemComponent() const
	{
		return AbilitySystemComponent;
	}

	FORCEINLINE UPlayerAttributeSet* GetAttributeSet() const
	{
		return AttributeSet;
	}

protected:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Initialize | GAS", Replicated)
	TObjectPtr<UPlayerAttributeSet> AttributeSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;


};
