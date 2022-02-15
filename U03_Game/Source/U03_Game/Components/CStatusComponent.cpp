#include "CStatusComponent.h"
#include "Global.h"

UCStatusComponent::UCStatusComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCStatusComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCStatusComponent::SetMove()
{
	bCanMove = true;
}

void UCStatusComponent::SetStop()
{
	bCanMove = false;
}




