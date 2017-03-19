#include "PipelineMaterial.h"

namespace DemoSFLpro
{
	PipelineMaterial::PipelineMaterial()
		: MaterialName("")
		, ElasticModulus(0)
		, PoissonsRatio(0)
		, ThermalExpCoeff(0)
		, IsPlastic(false)
		, HardeningPower(0)
		, HardeningCoeff(0)
	{
	}

	PipelineMaterial::PipelineMaterial(PipelineMaterial^ mat)
		: MaterialName(mat->MaterialName)
		, ElasticModulus(mat->ElasticModulus)
		, PoissonsRatio(mat->PoissonsRatio)
		, ThermalExpCoeff(mat->ThermalExpCoeff)
		, IsPlastic(mat->IsPlastic)
		, HardeningPower(mat->HardeningPower)
		, HardeningCoeff(mat->HardeningCoeff)
	{
	}

	PipelineMaterial::~PipelineMaterial()
	{
	}
}

