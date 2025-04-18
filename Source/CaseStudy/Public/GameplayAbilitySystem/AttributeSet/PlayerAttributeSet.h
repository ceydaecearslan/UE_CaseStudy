// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "PlayerAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthChanged);

UCLASS()
class CASESTUDY_API UPlayerAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	
	UPlayerAttributeSet();
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes | Health", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, Health);
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Attributes | Health")
	FOnHealthChanged OnHealthChanged;
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes | Health", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, MaxHealth)

protected:

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	
};
