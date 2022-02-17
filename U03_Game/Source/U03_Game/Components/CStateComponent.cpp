#include "CStateComponent.h"

UCStateComponent::UCStateComponent()
{

}

void UCStateComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UCStateComponent::SetIdleMode()
{
	ChangeType(EStateType::IDLE);
}

void UCStateComponent::SetRollMode()
{
	ChangeType(EStateType::ROLL);

}

void UCStateComponent::SetBackstepMode()
{
	ChangeType(EStateType::BACKSTEP);
}

void UCStateComponent::ChangeType(EStateType InNewType)
{
	EStateType prev = Type;
	Type = InNewType;

	if (OnStateTypeChanged.IsBound())
		OnStateTypeChanged.Broadcast(prev, InNewType);
}
