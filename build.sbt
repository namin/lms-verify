name := "lms-verify"

organization := "org.scala-lang.lms"

version := "0.1"

scalaOrganization := "org.scala-lang.virtualized"

scalaVersion := "2.11.2"

resolvers += Resolver.sonatypeRepo("snapshots")

libraryDependencies += "org.scala-lang.virtualized" % "scala-compiler" % "2.11.2"

libraryDependencies += "org.scala-lang.virtualized" % "scala-library" % "2.11.2"

libraryDependencies += "org.scala-lang.virtualized" % "scala-reflect" % "2.11.2"

libraryDependencies += "org.scala-lang.lms" %% "lms-core" % "1.0.0-SNAPSHOT"

libraryDependencies += "org.scalatest" % "scalatest_2.11" % "2.2.2" % "test"

libraryDependencies += "org.scala-lang.virtualized" % "scala-actors" % "2.11.2" % "test"

scalacOptions += "-Yvirtualize"

scalacOptions += "-deprecation"

parallelExecution in Test := false
