#include "CMontagesComponent.h"
#include "Global.h"
#include "GameFramework/Character.h"

UCMontagesComponent::UCMontagesComponent()
{

}

void UCMontagesComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<FMontageData*> datas;
	DataTable->GetAllRows<FMontageData>("", datas);

	for (int32 i = 0; i < (int32)EStateType::MAX; i++)
	{
		for (FMontageData* data : datas)
		{
			if ((EStateType)i == data->Type)
			{
				Datas[i] = data;

				continue;
			}
		}
	}
	for (const FMontageData* data : Datas) {
		if(!!data)
			CLog::Log(data->AnimMontage->GetPathName());
	}

}

void UCMontagesComponent::PlayRoll()
{
	PlayAnimMontage(EStateType::ROLL);
}

void UCMontagesComponent::PlayBackstep()
{
	PlayAnimMontage(EStateType::BACKSTEP);
}

void UCMontagesComponent::PlayAnimMontage(EStateType InStateType)
{
	ACharacter* character = Cast<ACharacter>(GetOwner());
	CheckNull(character);
	const FMontageData* data = Datas[(int32)InStateType];
	if (!!data) {
		CLog::Print(data->AnimMontage->GetName());
		if (!!data->AnimMontage)
			character->PlayAnimMontage(data->AnimMontage, data->PlayRate, data->StartSection);
	}
}
