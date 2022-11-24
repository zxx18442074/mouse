#include "yApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
yApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

yApp::yApp(InputParameters parameters) : MooseApp(parameters)
{
  yApp::registerAll(_factory, _action_factory, _syntax);
}

yApp::~yApp() {}

void
yApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"yApp"});
  Registry::registerActionsTo(af, {"yApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
yApp::registerApps()
{
  registerApp(yApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
yApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  yApp::registerAll(f, af, s);
}
extern "C" void
yApp__registerApps()
{
  yApp::registerApps();
}
