#pragma once

using namespace System;

namespace DemoSFLpro
{
	public ref class PipelineMaterial
	{
	public:
		PipelineMaterial();
		PipelineMaterial(PipelineMaterial^ mat);
		~PipelineMaterial();

	public:
		String^		MaterialName;
		double		ElasticModulus;
		double		PoissonsRatio;
		double		ThermalExpCoeff;
		bool		IsPlastic;
		double		HardeningPower;
		double		HardeningCoeff;
		double		SMYS, SUTS;

	public:

	};
}


