package org.tukorea.club.aop;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Component;

@Aspect
@Component
public class AopAspect {
	@Before("execution(* join(..))")
	public void beforeJoinMethod(JoinPoint jp) {
		System.out.println("[BeforeMethod] : 회원 가입 메소드 호출 전");
	}

	@After("execution(* join(..))")
	public void afterJoinMethod() {
		System.out.println("[AfterMethod] : 회원 가입 메소드 호출 후");
	}
	
	@Before("execution(* login(..))")
	public void beforeLoginMethod(JoinPoint jp) {
		System.out.println("[BeforeMethod] : 로그인 메소드 호출 전");
	}

	@After("execution(* login(..))")
	public void afterLoginMethod() {
		System.out.println("[AfterMethod] : 로그인 메소드 호출 후");
	}

}