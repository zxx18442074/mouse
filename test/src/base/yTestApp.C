//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "yTestApp.h"
#include "yApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
yTestApp::validParams()
{
  InputParameters params = yApp::validParams();
  return params;
}

yTestApp::yTestApp(InputParameters parameters) : MooseApp(parameters)
{
  yTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

yTestApp::~yTestApp() {}

void
yTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  yApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"yTestApp"});
    Registry::registerActionsTo(af, {"yTestApp"});
  }
}

void
yTestApp::registerApps()
{
  registerApp(yApp);
  registerApp(yTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
yTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  yTestApp::registerAll(f, af, s);
}
extern "C" void
yTestApp__registerApps()
{
  yTestApp::registerApps();
}
