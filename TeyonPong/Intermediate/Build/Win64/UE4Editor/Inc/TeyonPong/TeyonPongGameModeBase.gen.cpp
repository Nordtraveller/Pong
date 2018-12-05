// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TeyonPong/TeyonPongGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTeyonPongGameModeBase() {}
// Cross Module References
	TEYONPONG_API UClass* Z_Construct_UClass_ATeyonPongGameModeBase_NoRegister();
	TEYONPONG_API UClass* Z_Construct_UClass_ATeyonPongGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_TeyonPong();
// End Cross Module References
	void ATeyonPongGameModeBase::StaticRegisterNativesATeyonPongGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ATeyonPongGameModeBase_NoRegister()
	{
		return ATeyonPongGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ATeyonPongGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATeyonPongGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TeyonPong,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATeyonPongGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "TeyonPongGameModeBase.h" },
		{ "ModuleRelativePath", "TeyonPongGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATeyonPongGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATeyonPongGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATeyonPongGameModeBase_Statics::ClassParams = {
		&ATeyonPongGameModeBase::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A8u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ATeyonPongGameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATeyonPongGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATeyonPongGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATeyonPongGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATeyonPongGameModeBase, 3450105552);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATeyonPongGameModeBase(Z_Construct_UClass_ATeyonPongGameModeBase, &ATeyonPongGameModeBase::StaticClass, TEXT("/Script/TeyonPong"), TEXT("ATeyonPongGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATeyonPongGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
