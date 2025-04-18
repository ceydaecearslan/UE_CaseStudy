// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Blueprint/UserWidget.h"
#include "W_Ability.generated.h"

/**
 * 
 */

UCLASS()
class CASESTUDY_API UW_Ability : public UUserWidget
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Initialize")
	FGameplayTag CooldownTag;

	virtual void NativeConstruct() override;

	UFUNCTION()
	void BindOnCooldownTagChanged();

	UFUNCTION()
	void OnCooldownTagChanged(const FGameplayTag Tag, int32 NewCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCooldownStarted();
};
