#include "CActionData.h"
#include "Global.h"
#include "CEquipment.h"
#include "GameFramework/Character.h"

void UCActionData::BeginPlay(ACharacter* InOwnerCahracter)
{
    FTransform transform;
    if (!!EquipmentClass) {
        Equipment = InOwnerCahracter->GetWorld()->SpawnActorDeferred<ACEquipment>(EquipmentClass, transform, InOwnerCahracter);
        Equipment->AttachToComponent(InOwnerCahracter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true));
        Equipment->SetData(EquipmentData);
        Equipment->SetColor(EquipColor);
        UGameplayStatics::FinishSpawningActor(Equipment, transform);
    }
}
