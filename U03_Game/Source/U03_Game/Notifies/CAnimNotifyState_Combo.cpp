#include "CAnimNotifyState_Combo.h"
#include "Global.h"
#include "Actions/CActionData.h"
#include "ACtions/CDoAction_Melee.h"
#include "Components/CActionComponent.h"

FString UCAnimNotifyState_Combo::GetNotifyName_Implementation() const
{
	return "Combo";
}

void UCAnimNotifyState_Combo::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	CheckNull(MeshComp);
	CheckNull(MeshComp->GetOwner());

	UCActionComponent* action = CHelpers::GetComponent<UCActionComponent>(MeshComp->GetOwner());
	CheckNull(action);

	ACDoAction_Melee* melee = Cast<ACDoAction_Melee>(action->GetCurrent()->GetDoAction());
	CheckNull(melee);

	melee->EnableComboe();
}

void UCAnimNotifyState_Combo::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	CheckNull(MeshComp);
	CheckNull(MeshComp->GetOwner());

	UCActionComponent* action = CHelpers::GetComponent<UCActionComponent>(MeshComp->GetOwner());
	CheckNull(action);

	ACDoAction_Melee* melee = Cast<ACDoAction_Melee>(action->GetCurrent()->GetDoAction());
	CheckNull(melee);

	melee->DisableComboe();
}

