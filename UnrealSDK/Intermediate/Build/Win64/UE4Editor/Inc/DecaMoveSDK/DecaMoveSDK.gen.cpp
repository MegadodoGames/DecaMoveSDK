// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DecaMoveSDK/Public/DecaMoveSDK.h"
#include "Engine/Classes/Engine/GameInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDecaMoveSDK() {}
// Cross Module References
	DECAMOVESDK_API UClass* Z_Construct_UClass_UDecaMoveLoadSubsystem_NoRegister();
	DECAMOVESDK_API UClass* Z_Construct_UClass_UDecaMoveLoadSubsystem();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	UPackage* Z_Construct_UPackage__Script_DecaMoveSDK();
// End Cross Module References
	void UDecaMoveLoadSubsystem::StaticRegisterNativesUDecaMoveLoadSubsystem()
	{
	}
	UClass* Z_Construct_UClass_UDecaMoveLoadSubsystem_NoRegister()
	{
		return UDecaMoveLoadSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UDecaMoveLoadSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDecaMoveLoadSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_DecaMoveSDK,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDecaMoveLoadSubsystem_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DecaMoveSDK.h" },
		{ "ModuleRelativePath", "Public/DecaMoveSDK.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDecaMoveLoadSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDecaMoveLoadSubsystem>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UDecaMoveLoadSubsystem_Statics::ClassParams = {
		&UDecaMoveLoadSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UDecaMoveLoadSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDecaMoveLoadSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDecaMoveLoadSubsystem()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UDecaMoveLoadSubsystem_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UDecaMoveLoadSubsystem, 42276565);
	template<> DECAMOVESDK_API UClass* StaticClass<UDecaMoveLoadSubsystem>()
	{
		return UDecaMoveLoadSubsystem::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDecaMoveLoadSubsystem(Z_Construct_UClass_UDecaMoveLoadSubsystem, &UDecaMoveLoadSubsystem::StaticClass, TEXT("/Script/DecaMoveSDK"), TEXT("UDecaMoveLoadSubsystem"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDecaMoveLoadSubsystem);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
